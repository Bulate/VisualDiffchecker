#ifndef RESULTSDOCKWIDGET_H
#define RESULTSDOCKWIDGET_H

#include <QDockWidget>
#include <QListWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QFile>
#include <QDir>
#include <QFileInfoList>

class StandardInputOutputInspector;
class Diagnostic;

class ResultsDockWidget : public QDockWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ResultsDockWidget)
public:
    explicit ResultsDockWidget(QWidget* parent = nullptr, Qt::WindowFlags flags = 0);
	void generateDiffFile(  const QFileInfoList &outputInfoList
							, const QFileInfoList &programOutputInfoList
                            , const QDir workingDirectoryPath
							, int index );
	void createTestCasesTabs(int testCasesCount
							 , const QList<QFile *> &testCaseInputs
							 , const QList<QFile *> &testCaseOutputs
							 , const QList<QFile *> &testProgramOutputs
							 , const QList<bool> testCaseState
							 , const QFileInfoList &outputInfoList
							 , const QFileInfoList &programOutputInfoList
                             , const QDir workingDirectoryPath );

protected:
    /// Manages the tabs for output generated by build and debug tools
    QTabWidget* resultsTabWidget;
    QTextEdit* compilerOutputTab;
    /// A control to display compiler, linker and debugger output
    QListWidget* toolsOutput;
    QString workingDirectoryPath;

  //QDir workingDirectory;
  /// Let user compare differences between test case's input/output/error and his/her solution
  StandardInputOutputInspector* standardInputOutputInspector = nullptr;
 public:
  void appendDiagnostic(const Diagnostic* diagnostic);


public slots:

  /// Appends a message sent by the debugger (e.g. GDB)
  void appendDebuggerMessage(QtMsgType type, const QString& category, const QString& message);
//  /// Let user compare differences between test case's input/output/error and his/her solution
//  StandardInputOutpInspector* standardInputOutputInspector = nullptr;
  /// Called when a new compiling process has started, in order to clear old results
  void clear();
  //void generateHtmlFile( QString outputFileHtmlfPath, QString outputFileDiffPath);
  void callDiff2Html();


private slots:
};

#endif // RESULTSDOCKWIDGET_H
