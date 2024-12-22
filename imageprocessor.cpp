#include "imageprocessor.h"
#include <QFileDialog>
#include <QDebug>

ImageProcessor::ImageProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QStringLiteral("影像處理器"));
    central = new QWidget();
    mainLayout = new QHBoxLayout(central);
    imgWin = new QLabel();
    QPixmap *initPixmap = new QPixmap(300,200);
    initPixmap->fill(QColor(128,128,128));
    imgWin->resize(300,200);
    imgWin->setPixmap(*initPixmap);
    imgWin->setScaledContents(true);
    anotherWin.setScaledContents(true);
    mainLayout->addWidget(imgWin);
    setCentralWidget(central);
    createActions();
    createMenus();
    createToolBars();




}

ImageProcessor::~ImageProcessor() {

}
void ImageProcessor::createActions()
{
    openFileAction = new QAction(QStringLiteral("開啟檔案"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(QStringLiteral("開啟影像檔案"));

    exitAction = new QAction(QStringLiteral("結束"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(QStringLiteral("退出程式"));

    enlargeAction = new QAction(QStringLiteral("放大"),this);
    enlargeAction->setShortcut(tr("Ctrl+L"));
    enlargeAction->setStatusTip(QStringLiteral("放大影像"));
    shrinkAction = new QAction(QStringLiteral("縮小"),this);
    shrinkAction->setShortcut(tr("Ctrl+D"));
    shrinkAction->setStatusTip(QStringLiteral("縮小影像"));

    connect(openFileAction,SIGNAL(triggered()),this, SLOT(showOpenFile()));
    connect(exitAction,SIGNAL(triggered()),this, SLOT(close()));
    connect(enlargeAction,SIGNAL(triggered()),this, SLOT(enlargeImage()));


}
void ImageProcessor::createMenus()
{
    fileMenu = menuBar()->addMenu(QStringLiteral("檔案(&F)"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(exitAction);
    editMenu = menuBar()->addMenu(QStringLiteral("工具(&E)"));
    editMenu->addAction(enlargeAction);
    editMenu->addAction(shrinkAction);


}
void ImageProcessor::createToolBars()
{
    fileTool = addToolBar(tr("file"));
    fileTool->addAction(openFileAction);


}
void ImageProcessor::loadFile(QString filename)
{
    img.load(filename);
    imgWin->setPixmap(QPixmap::fromImage(img));

}
void ImageProcessor::showOpenFile()
{
    filename =QFileDialog::getOpenFileName(this,QStringLiteral("開啟影像檔案"),tr("."),
                                          "all (*.*);;png (*.png);;jpg (*.jpg);;bmp (*.bmp)");
    if (!filename.isEmpty())
    {
        loadFile(filename);
    }


}
void ImageProcessor::enlargeImage()
{
    QImage largeimg;
    largeimg = img.scaled(img.width()*2,img.height()*2);

    anotherWin.setPixmap(QPixmap::fromImage(largeimg));
    anotherWin.show();


}
void ImageProcessor::shrinkImage()
{

}
