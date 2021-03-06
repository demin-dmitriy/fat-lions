#include "animal_view.h"

#include <cmath>

//const char* LION_COLOR = "#FFCC33";

const double PI = 3.14159265;

AnimalView::AnimalView(const char* color, const Animal& animal, QObject* parent) : QObject(parent), QGraphicsItem(),
        color_(color), position_(animal.position_) {
    double arg = double(animal.direction_.y_ * (-1)) / sqrt(double(animal.direction_.x_ * animal.direction_.x_ + animal.direction_.y_ * animal.direction_.y_));
    if (animal.direction_.x_ >= 0) {
        angle_ = acos(arg) * 180.0 / PI;
    } else {
        angle_ = 360.0 - acos(arg) * 180.0 / PI;
    }
    setRotation(angle_);
};

QRectF AnimalView::boundingRect() const {
	return QRectF(-30, -30, 60, 60);
};

void AnimalView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPolygon polygon;
    polygon << QPoint(0, -10) << QPoint(5, 5) << QPoint(-5,5);
    painter->setBrush(QColor(color_));
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
};
