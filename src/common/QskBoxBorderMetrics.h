/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_BOX_BORDER_METRICS_H
#define QSK_BOX_BORDER_METRICS_H

#include "QskMargins.h"

#include <qmetatype.h>
#include <qnamespace.h>
#include <qsize.h>

class QSK_EXPORT QskBoxBorderMetrics
{
  public:
    constexpr QskBoxBorderMetrics();

    constexpr QskBoxBorderMetrics(
        qreal width, Qt::SizeMode = Qt::AbsoluteSize );

    constexpr QskBoxBorderMetrics( qreal left, qreal top,
        qreal right, qreal bottom, Qt::SizeMode = Qt::AbsoluteSize );

    constexpr QskBoxBorderMetrics(
        const QskMargins& widths, Qt::SizeMode sizeMode = Qt::AbsoluteSize );

    ~QskBoxBorderMetrics();

    bool operator==( const QskBoxBorderMetrics& ) const;
    bool operator!=( const QskBoxBorderMetrics& ) const;

    bool isNull() const;

    void setWidthAt( Qt::Edges, qreal width );
    qreal widthAt( Qt::Edge ) const;

    void setWidths( const QskMargins& );
    const QskMargins& widths() const;

    void setSizeMode( Qt::SizeMode );
    Qt::SizeMode sizeMode() const;

    QskBoxBorderMetrics interpolated(
        const QskBoxBorderMetrics&, qreal value ) const;

    QskBoxBorderMetrics toAbsolute( const QSizeF& ) const;

    uint hash( uint seed = 0 ) const;

    static QVariant interpolate( const QskBoxBorderMetrics&,
        const QskBoxBorderMetrics&, qreal progress );

  private:
    QskMargins m_widths;
    Qt::SizeMode m_sizeMode : 2;
};

inline constexpr QskBoxBorderMetrics::QskBoxBorderMetrics()
    : m_sizeMode( Qt::AbsoluteSize )
{
}

inline constexpr QskBoxBorderMetrics::QskBoxBorderMetrics(
        qreal width, Qt::SizeMode sizeMode )
    : m_widths( width )
    , m_sizeMode( sizeMode )
{
}

inline constexpr QskBoxBorderMetrics::QskBoxBorderMetrics(
        const QskMargins& widths, Qt::SizeMode sizeMode )
    : m_widths( widths )
    , m_sizeMode( sizeMode )
{
}

inline constexpr QskBoxBorderMetrics::QskBoxBorderMetrics(
        qreal left, qreal top, qreal right, qreal bottom, Qt::SizeMode sizeMode )
    : m_widths( left, top, right, bottom )
    , m_sizeMode( sizeMode )
{
}

inline bool QskBoxBorderMetrics::operator!=( const QskBoxBorderMetrics& other ) const
{
    return !( *this == other );
}

inline bool QskBoxBorderMetrics::isNull() const
{
    return m_widths.isNull();
}

inline const QskMargins& QskBoxBorderMetrics::widths() const
{
    return m_widths;
}

inline qreal QskBoxBorderMetrics::widthAt( Qt::Edge edge ) const
{
    return m_widths.marginAt( edge );
}

inline Qt::SizeMode QskBoxBorderMetrics::sizeMode() const
{
    return m_sizeMode;
}

#ifndef QT_NO_DEBUG_STREAM

QSK_EXPORT QDebug operator<<( QDebug, const QskBoxBorderMetrics& );

#endif

//Q_DECLARE_TYPEINFO( QskBoxBorderMetrics, Q_MOVABLE_TYPE );
Q_DECLARE_METATYPE( QskBoxBorderMetrics )

#endif
