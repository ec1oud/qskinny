/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_SKIN_H
#define QSK_SKIN_H

#include "QskAspect.h"

#include <qcolor.h>
#include <qobject.h>

#include <memory>
#include <type_traits>
#include <unordered_map>

class QskControl;
class QskSkinnable;
class QskSkinlet;

class QskColorFilter;
class QskGraphic;
class QskGraphicProvider;

class QskAnimationHint;
class QskSkinHintTable;

class QskMargins;
class QskGradient;
class QskBoxShapeMetrics;
class QskBoxBorderMetrics;
class QskBoxBorderColors;

class QSK_EXPORT QskSkin : public QObject
{
    Q_OBJECT

    using Inherited = QObject;

  public:
    enum SkinFontRole
    {
        DefaultFont = 0,

        TinyFont,
        SmallFont,
        MediumFont,
        LargeFont,
        HugeFont
    };

    Q_ENUM( SkinFontRole )

    QskSkin( QObject* parent = nullptr );
    ~QskSkin() override;

    template< typename Control, typename Skinlet >
    void declareSkinlet();

    virtual void resetColors( const QColor& accent );

    void setColor( QskAspect::Aspect, Qt::GlobalColor );
    void setColor( QskAspect::Aspect, QRgb );
    void setColor( QskAspect::Aspect, const QColor& );

    QColor color( QskAspect::Aspect ) const;

    void setMetric( QskAspect::Aspect, qreal metric );
    qreal metric( QskAspect::Aspect ) const;

    void setMargins( QskAspect::Aspect, const QskMargins& );
    QskMargins margins( QskAspect::Aspect ) const;

    void setGradient( QskAspect::Aspect, const QskGradient& );
    QskGradient gradient( QskAspect::Aspect ) const;

    void setBoxShape( QskAspect::Aspect, qreal radius, Qt::SizeMode = Qt::AbsoluteSize );
    void setBoxShape( QskAspect::Aspect, qreal topLeft, qreal topRight,
        qreal bottomLeft, qreal bottomRight, Qt::SizeMode = Qt::AbsoluteSize );

    void setBoxShape( QskAspect::Aspect, const QskBoxShapeMetrics& );
    QskBoxShapeMetrics boxShape( QskAspect::Aspect ) const;

    void setBoxBorderMetrics( QskAspect::Aspect, qreal left, qreal top,
        qreal right, qreal bottom, Qt::SizeMode = Qt::AbsoluteSize );

    void setBoxBorderMetrics( QskAspect::Aspect, const QskBoxBorderMetrics& );
    QskBoxBorderMetrics boxBorderMetrics( QskAspect::Aspect ) const;

    void setBoxBorderColors( QskAspect::Aspect, const QskBoxBorderColors& );
    QskBoxBorderColors boxBorderColors( QskAspect::Aspect ) const;

    void setAnimation( QskAspect::Aspect, QskAnimationHint );
    QskAnimationHint animation( QskAspect::Aspect ) const;

    void setSkinHint( QskAspect::Aspect, const QVariant& hint );
    const QVariant& skinHint( QskAspect::Aspect ) const;

    void setGraphicFilter( int graphicRole, const QskColorFilter& );
    void resetGraphicFilter( int graphicRole );
    QskColorFilter graphicFilter( int graphicRole ) const;

    void setFontRole( QskAspect::Aspect, int fontRole );
    void setGraphicRole( QskAspect::Aspect, int graphicRole );

    void setFont( int fontRole, const QFont& );
    void resetFont( int fontRole );
    QFont font( int fontRole ) const;

    void setupFonts( const QString& family,
        int weight = -1, bool italic = false );

    virtual QskGraphic symbol( int symbolType ) const;

    void addGraphicProvider( const QString& providerId, QskGraphicProvider* );
    QskGraphicProvider* graphicProvider( const QString& providerId ) const;
    bool hasGraphicProvider() const;

    virtual const int* dialogButtonLayout( Qt::Orientation ) const;

    QskSkinlet* skinlet( const QskSkinnable* );

    const QskSkinHintTable& hintTable() const;

    const std::unordered_map< int, QFont >& fonts() const;
    const std::unordered_map< int, QskColorFilter >& graphicFilters() const;

  protected:
    QskSkinHintTable& skinHintTable();

  private:
    void declareSkinlet( const QMetaObject* controlMetaObject,
        const QMetaObject* skinMetaObject );

    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

template< typename Control, typename Skinlet >
inline void QskSkin::declareSkinlet()
{
    Q_STATIC_ASSERT( ( std::is_base_of< QskControl, Control >::value ) );
    Q_STATIC_ASSERT( ( std::is_base_of< QskSkinlet, Skinlet >::value ) );
    declareSkinlet( &Control::staticMetaObject, &Skinlet::staticMetaObject );
}

#endif
