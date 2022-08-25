# CMakeList.txt : CMake project for LAB6-G02-TP056103-TP057431-TP062951, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (DSTR "DSTR.cpp" "Headers/DSTR.h" LoginPage.cpp Headers/LoginPage.h SalesExecutive.cpp Headers/SalesExecutive.h Admin.cpp Headers/Admin.h MenuItems.cpp Headers/MenuItems.h SalesMenu_ViewOrders.cpp Headers/SalesMenu_ViewOrders.h SalesMenu_NewPurchase.cpp Headers/SalesMenu_NewPurchase.h AdminMenu_ReportGen.cpp Headers/AdminMenu_ReportGen.h Customers/CustomerNode.cpp Customers/CustomerNode.h Customers/CustomerFunctions.cpp Customers/CustomerFunctions.h Orders/OrderNode.cpp Orders/OrderNode.h Orders/OrderFunctions.cpp Orders/OrderFunctions.h Products/ProductNode.cpp Products/ProductNode.h Products/ProductFunctions.cpp Products/ProductFunctions.h Validate.cpp Headers/Validate.h OrderQueue.cpp Headers/OrderQueue.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DSTR PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
