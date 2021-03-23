#include "RecurrencePluginActivator.h"

#include "QRecurrenceView.h"

#include <usModuleInitialization.h>

ctkPluginContext* RecurrencePluginActivator::m_Context = nullptr;

US_INITIALIZE_MODULE 

void RecurrencePluginActivator::start(ctkPluginContext *context)
{
  BERRY_REGISTER_EXTENSION_CLASS(QRecurrenceView, context)

  m_Context = context;
}

void RecurrencePluginActivator::stop(ctkPluginContext*)
{
}

ctkPluginContext* RecurrencePluginActivator::getContext()
{
  return m_Context;
}
