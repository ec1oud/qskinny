/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_STATUS_INDICATOR_H
#define QSK_STATUS_INDICATOR_H

#include "QskControl.h"

class QskGraphic;
class QskColorFilter;

class QSK_EXPORT QskStatusIndicator : public QskControl
{
    Q_OBJECT

    Q_PROPERTY( int status READ status() WRITE setStatus NOTIFY statusChanged )

    using Inherited = QskControl;

  public:
    QSK_SUBCONTROLS( Graphic )

    QskStatusIndicator( QQuickItem* parent = nullptr );
    ~QskStatusIndicator() override;

    Q_INVOKABLE QUrl source( int status ) const;
    Q_INVOKABLE void setSource( int status, const QUrl& url );

    QskGraphic graphic( int status ) const;
    void setGraphic( int status, const QskGraphic& );

    virtual QskColorFilter graphicFilter( int status ) const;
    virtual QskGraphic loadSource( const QUrl& ) const;

    qreal heightForWidth( qreal width ) const override;
    qreal widthForHeight( qreal height ) const override;

    QSizeF contentsSizeHint() const override;

    int status() const;
    bool hasStatus( int status ) const;

  public Q_SLOTS:
    void setStatus( int status );

  Q_SIGNALS:
    void statusChanged( int status );

  protected:
    void changeEvent( QEvent* ) override;
    void updateLayout() override;

  private:
    qreal sizeConstraint( Qt::Orientation, qreal ) const;

    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

#endif
