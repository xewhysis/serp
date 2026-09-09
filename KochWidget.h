#ifndef KOCHWIDGET_H
#define KOCHWIDGET_H

#include <QWidget>
#include <QPointF>
#include <QPainter>

class KochWidget : public QWidget {
    Q_OBJECT

public:
    explicit KochWidget(QWidget *parent = nullptr);
    void setIteration(int iteration);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawKoch(QPainter &painter, const QPointF &a, const QPointF &b,int iteration);
    int m_iteration = 0;
};

#endif