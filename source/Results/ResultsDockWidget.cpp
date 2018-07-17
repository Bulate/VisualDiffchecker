#include "ResultsDockWidget.h"
#include "StandardInputOutputInspector.h"

ResultsDockWidget::ResultsDockWidget(QWidget* parent, Qt::WindowFlags flags)
    : QDockWidget(tr("Results"), parent, flags)
    //, compiler(nullptr)
{
    setFeatures(QDockWidget::DockWidgetMovable);
//	// QMainWindow requires all its direct children have a name to store preferences
    setObjectName("ResultsDockWidget");

//	// Each message control is placed within a tab control
    resultsTabWidget = new QTabWidget(this);
    setWidget(resultsTabWidget);

//	// Add the first tab (page): the unit problem description
    compilerOutputTab = new QTextEdit();
    compilerOutputTab->setReadOnly(true);
//	unitDescription->document()->setDefaultFont(BotNeumannApp::getRobotFont());
//	unitDescription->document()->setDefaultStyleSheet("pre { margin-left: 1em; background: #ddd; }");
//	QIcon unitDescriptionIcon(":/button_information.svg");
   resultsTabWidget->addTab(compilerOutputTab, tr("Compiler Output"));

//	// Add the second tab: output generated by build and debug tools
//	toolsOutput = new QListWidget();
//	toolsOutput->setFont( BotNeumannApp::getMonospacedFont() );
//	toolsOutput->setWordWrap(true);
//	toolsOutput->setTextElideMode(Qt::ElideNone); // Avoid ellipsis for large texts
//	connect(toolsOutput, SIGNAL(currentRowChanged(int)), this, SLOT(toolsOutputRowChanged(int)));
//	//toolsOutput->setStyleSheet("QListWidget::item { border-bottom: 1px dashed gray; }");
//	QIcon toolsOutputIcon(":/unit_playing/buttons/info.svg");
//	messagesTabWidget->addTab(toolsOutput, toolsOutputIcon, tr("Compile output"));

//	// Some messages received by the LogManager may be shown in the GUI
//	LogManager::setMessagesArea(this);

   standardInputOutputInspector = new StandardInputOutputInspector();
   resultsTabWidget->addTab(standardInputOutputInspector,tr("Input/Ouput/Expected"));


//	// Add a third tab: for player's solution input/output
//	standardInputOutputInspector = new StandardInputOutputInspector();
//	QIcon inputOutputIcon(":/unit_playing/buttons/input_output.svg");
//	messagesTabWidget->addTab(standardInputOutputInspector, inputOutputIcon, tr("Input/output"));

}
