/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_LAYOUT_CONSTRAINT_H
#define QSK_LAYOUT_CONSTRAINT_H

#include "QskGlobal.h"

#include <qnamespace.h>
#include <qquickitem.h>
#include <limits>

class QskSizePolicy;
class QskControl;

namespace std { template< typename T > class function; }

namespace QskLayoutConstraint
{
    enum Type
    {
        WidthForHeight,
        HeightForWidth
    };

    QSK_EXPORT bool hasDynamicConstraint( const QQuickItem* );
    QSK_EXPORT qreal heightForWidth( const QQuickItem*, qreal width );
    QSK_EXPORT qreal widthForHeight( const QQuickItem*, qreal height );

    QSK_EXPORT qreal constrainedMetric(
        Type, const QskControl*, qreal value,
        std::function< qreal( Type, const QskControl*, qreal ) > );

    QSK_EXPORT qreal constrainedChildrenMetric( Type, const QskControl*, qreal width );

    QSK_EXPORT QSizeF effectiveConstraint( const QQuickItem*, Qt::SizeHint );
    QSK_EXPORT QskSizePolicy sizePolicy( const QQuickItem* );

    // bounded by Qt::MinimumSize/Qt::MaximumSize
    QSK_EXPORT QSizeF boundedSize( const QQuickItem*, const QSizeF& );

    QSK_EXPORT QSizeF adjustedSize( const QQuickItem*, const QSizeF& );

    // QGridLayoutEngine internally uses FLT_MAX
    const qreal unlimited = std::numeric_limits< float >::max();
}

#endif
