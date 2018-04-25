#ifndef NAVIGATORWIDGET_H
#define NAVIGATORWIDGET_H

#include <QWidget>
#include <QVector>
#include <QMouseEvent>

class NavigatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigatorWidget(QWidget *parent = nullptr);

    int size() const { return m_items.size(); }
    void setSize(int value);

    float value(int index) const { return m_items.at(index); }
    void setValue(int index, float value);

    int selectedIndex() const { return m_selectedIndex; }
    void setSelectedIndex(int value);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int m_selectedIndex;
    QVector<float> m_items;

signals:
    void selectedIndexChanged();

public slots:
};

#endif // NAVIGATORWIDGET_H
