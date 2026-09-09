#include "KochWidget.h"

#include <QPaintEvent>
#include <QtMath>

KochWidget::KochWidget(QWidget *parent)
    : QWidget(parent) {
    setMinimumSize(700, 400);
}

void KochWidget::setIteration(int iteration) {
    m_iteration = iteration;
    update();
}

void KochWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(rect(), Qt::white);

    QPen pen(Qt::black);
    pen.setWidth(3);

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    double margin = 50.0;

    QPointF start(
        margin,
        height() / 2.0 + 50.0
        );

    QPointF end(
        width() - margin,
        height() / 2.0 + 50.0
        );

    drawKoch(
        painter,
        start,
        end,
        m_iteration
        );
}

void KochWidget::drawKoch(
    QPainter &painter,
    const QPointF &a,
    const QPointF &b,
    int iteration
    )
{
    if (iteration == 0)
    {
        painter.drawLine(a, b);
        return;
    }

    QPointF p1(
        a.x() + (b.x() - a.x()) / 3.0,
        a.y() + (b.y() - a.y()) / 3.0
        );

    QPointF p2(
        a.x() + (b.x() - a.x()) * 2.0 / 3.0,
        a.y() + (b.y() - a.y()) * 2.0 / 3.0
        );

    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();

    double angle = qDegreesToRadians(-60.0);

    QPointF peak(
        p1.x() + dx * qCos(angle) - dy * qSin(angle),
        p1.y() + dx * qSin(angle) + dy * qCos(angle)
        );

    drawKoch(
        painter,
        a,
        p1,
        iteration - 1
        );

    drawKoch(
        painter,
        p1,
        peak,
        iteration - 1
        );

    drawKoch(
        painter,
        peak,
        p2,
        iteration - 1
        );

    drawKoch(
        painter,
        p2,
        b,
        iteration - 1
        );
}