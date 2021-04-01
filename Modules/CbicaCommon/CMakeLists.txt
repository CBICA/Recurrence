
mitk_create_module(
  INCLUDE_DIRS PUBLIC include
  PACKAGE_DEPENDS ITK Qt5|Core+Network
  DEPENDS PUBLIC MitkCore
)

# You can add subdirectories as needed 
#add_subdirectory(cmdapps) # -> for cmd app

# You can also add additional commands here as needed.
