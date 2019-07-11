#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionnew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
            currentFile = filename;
             if(!file.open(QIODevice::ReadOnly | QFile::Text))
            {
                   QMessageBox::warning(this, "warning", "Cannot open file : " + file.errorString());
            }
            setWindowTitle(filename);
            QTextStream in(&file);
            QString text = in.readAll();
            ui->textEdit->setText(text);
            file.close();

}

void MainWindow::on_actionsave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "save this file");
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
   {
          QMessageBox::warning(this, "warning", "Cannot cannt save file lmao : " + file.errorString());
          return;
   }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();



}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "warning", "Cannot Access printer");
        return;
    }
    ui->textEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();

}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();

}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();

}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();

}

void MainWindow::on_actionRedo_lmao_triggered()
{
    ui->textEdit->redo();

}
