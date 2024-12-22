#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QHBoxLayout>
#include <QImage>
#include <QPixmap>
#include <QLabel>

class ImageProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImageProcessor(QWidget *parent = nullptr);
    ~ImageProcessor();
    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);
private slots:
    void showOpenFile();
    void enlargeImage();
    void shrinkImage();
private:
    QWidget     *central;
    QMenu       *fileMenu;
    QMenu       *editMenu;
    QToolBar    *fileTool;
    QAction     *openFileAction;
    QAction     *exitAction;
    QAction     *enlargeAction;
    QAction     *shrinkAction;
    QHBoxLayout *mainLayout;
    QImage      img;
    QLabel      *imgWin;
    QString     filename;
    QLabel anotherWin;
};
#endif // IMAGEPROCESSOR_H
