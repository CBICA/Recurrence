
mitk_create_module(
  INCLUDE_DIRS PUBLIC include
  PACKAGE_DEPENDS ITK|IOCSV VTK|FiltersStatistics Qt5|Core+Widgets OpenCV# External package dependencies added here
  DEPENDS PUBLIC MitkCbicaCommon#MitkCore MitkPython# Module dependencies - be sure to add as needed
)

# You can add subdirectories as needed 
#add_subdirectory(cmdapps) # -> for cmd app

# You can also add additional commands here as needed.
