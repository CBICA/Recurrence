#include "QRecurrenceView.h"

#include <QMessageBox>

const std::string QRecurrenceView::VIEW_ID =
    "upenn.cbica.deepmrseg.view";


QRecurrenceView::QRecurrenceView()
{
  // ---- General setup operations ----
}

QRecurrenceView::~QRecurrenceView()
{

}

void QRecurrenceView::CreateQtPartControl(QWidget *parent)
{
  // ---- Setup the basic GUI of this view ----
  m_Parent = parent;
  m_Controls.setupUi(parent);

  //hide temporarily since python side doesn't yet thrown progress
  m_Controls.progressBar->hide(); 

  //temporarily disabled since this would change
  m_Controls.groupBox_DataSelection->setDisabled(true); 

  connect(m_Controls.pushButtonRun, SIGNAL(clicked()),
	  this, SLOT(OnDoStuffButtonClicked()));

  connect(m_Controls.pushButtonRunScript, SIGNAL(clicked()),
	  this, SLOT(OnRunScriptClicked()));
  
}

void QRecurrenceView::Activated()
{
  // Not yet implemented
}

void QRecurrenceView::Deactivated()
{
  // Not yet implemented
}

void QRecurrenceView::Visible()
{
  // Not yet implemented
}

void QRecurrenceView::Hidden()
{
  // Not yet implemented
}

/************************************************************************/
/* protected slots                                                      */
/************************************************************************/

void QRecurrenceView::OnDoStuffButtonClicked()
{
    //QMessageBox msgError;
    //msgError.setText("Hello, I am DeepMRSeg.");
    //msgError.setIcon(QMessageBox::Critical);
    //msgError.setWindowTitle("DeepMRSeg");
    //msgError.exec();

		//get datastorage( we use it further down )
	auto ds = this->GetDataStorage();

	//get selected nodes
	QList<mitk::DataNode::Pointer> nodes = this->GetDataManagerSelection();

	//we don't handle the case where data is not loaded or more than 1 nodes are selected
	if (nodes.empty() || nodes.size() > 1)
	{
		QMessageBox msgError;
		msgError.setText("Please load and select a dataset.");
		msgError.setIcon(QMessageBox::Critical);
		msgError.setWindowTitle("selection error");
		msgError.exec();
	}
	else
	{
		//get first node from list
		mitk::DataNode *node = nodes.front();

		auto data = node->GetData();
		// node has data?
		if (data != nullptr)
		{
			// get smart pointer from data
			mitk::Image::Pointer image = dynamic_cast<mitk::Image*>(data);
			// ... has IMAGE data? :D
			if (image.IsNotNull())
			{
				auto imageName = node->GetName();
				MITK_INFO << "Processing image \"" << imageName << "\" ...";

				// get our inverter filter class (note this isn't a proper ITK-style smart pointer --
				// change this in your code if you are using a proper filter.
				auto filter = captk::DeepMRSegMediator();
				auto filterPtr = &filter;

				filterPtr->SetInput(image);
				filterPtr->Update();
				mitk::Image::Pointer processedImage = filterPtr->GetOutput();

				// Double check to make sure we aren't adding uninitalized or null images. 
				if (processedImage.IsNull() || !processedImage->IsInitialized())
					// Could do more diagnostics or raise an error message here...
					return;

				MITK_INFO << "  done";

				auto processedImageDataNode = mitk::DataNode::New(); // Create a new node
				MITK_INFO << "Adding to a data node";
				processedImageDataNode->SetData(processedImage); // assign the inverted image to the node

				MITK_INFO << "Adding a name";
				// Add a suffix so users can easily see what it is
				QString name = QString("%1_inverted").arg(imageName.c_str());
				processedImageDataNode->SetName(name.toStdString());

				// Finally, add the new node to the data storage.
				ds->Add(processedImageDataNode);

			}
		}
	}
}

/************************************************************************/
/* protected                                                            */
/************************************************************************/

void QRecurrenceView::OnRunScriptClicked()
{
	MITK_INFO << "  script button clicked ";
	captk::DeepMRSegMediator dmrs_mediator;
	dmrs_mediator.RunSampleScript();
}

void QRecurrenceView::OnSelectionChanged(berry::IWorkbenchPart::Pointer, const QList<mitk::DataNode::Pointer>& /*nodes*/)
{

}

void QRecurrenceView::OnPreferencesChanged(const berry::IBerryPreferences* /*prefs*/)
{

}

void QRecurrenceView::NodeAdded(const mitk::DataNode* /*node*/)
{

}

void QRecurrenceView::NodeRemoved(const mitk::DataNode* /*node*/)
{

}

void QRecurrenceView::SetFocus()
{

}

void QRecurrenceView::UpdateControls()
{
  // Here you can hide views that are not useful and more
}

void QRecurrenceView::InitializeListeners()
{

}