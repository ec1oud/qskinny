/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_TEXT_RENDERER_H
#define QSK_TEXT_RENDERER_H

#include "QskNamespace.h"
#include <qnamespace.h>
#include <qquickitem.h>

class QskTextColors;
class QskTextOptions;

namespace QskTextRenderer
{
    QSK_EXPORT void updateNode(
        const QString&, const QFont&, const QskTextOptions&, Qsk::TextStyle,
        const QskTextColors&, Qt::Alignment, const QRectF&,
        const QQuickItem*, QSGTransformNode* );

    QSK_EXPORT QSizeF textSize(
        const QString&, const QFont&, const QskTextOptions& );

    QSK_EXPORT QSizeF textSize(
        const QString&, const QFont&, const QskTextOptions&, const QSizeF& );
}

#endif
