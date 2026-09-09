#include "KochWidget.h"

#include <QPaintEvent>
#include <QtMath>

KochWidget::KochWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(600, 400);
    setAutoFillBackground(true);
}

void KochWidget::setIteration(int iteration)
{
    m_iteration = iteration;
    update();
}

void KochWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(rect(), Qt::white);

    QPen pen(Qt::black);
    pen.setWidth(2);

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    double size = qMin(width(), height()) * 0.65;

    double centerX = width() / 2.0;
    double centerY = height() / 2.0;

    double triangleHeight = size * qSqrt(3.0) / 2.0;

    QPointF top(
        centerX,
        centerY - triangleHeight / 2.0
        );

    QPointF left(
        centerX - size / 2.0,
        centerY + triangleHeight / 2.0
        );

    QPointF right(
        centerX + size / 2.0,
        centerY + triangleHeight / 2.0
        );

    drawKoch(
        painter,
        top,
        right,
        m_iteration
        );

    drawKoch(
        painter,
        right,
        left,
        m_iteration
        );

    drawKoch(
        painter,
        left,
        top,
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