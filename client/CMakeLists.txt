find_package ( PkgConfig REQUIRED )

pkg_check_modules ( OPENSSL openssl REQUIRED )

include_directories ( ${OPENSSL_INCLUDE_DIRS} )
link_directories ( ${OPENSSL_LINK_DIRS} )

set ( SRC_TOP "${CMAKE_SOURCE_DIR}/client/" )

set ( CIPHER_SOURCES
  ${SRC_TOP}/main.c
)

add_executable ( openssl-client-test ${CIPHER_SOURCES} )

target_include_directories ( openssl-client-test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries ( openssl-client-test "-pthread" ${OPENSSL_LIBRARIES} )

install ( TARGETS openssl-client-test DESTINATION bin )
