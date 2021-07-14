cmake_minimum_required(VERSION 3.20)

project(ctcilib)

set(LIBRARY_NAME ctcilib)
set(LIBRARY_HEADERS_DIR include/${LIBRARY_NAME})
set(LIBRARY_HEADERS 
    ${LIBRARY_HEADERS_DIR}/assorted_methods.h
    ${LIBRARY_HEADERS_DIR}/BitVector.h
    ${LIBRARY_HEADERS_DIR}/BTreePrinter.h
    ${LIBRARY_HEADERS_DIR}/HashMapList.h
    ${LIBRARY_HEADERS_DIR}/LinkedListNode.h
    ${LIBRARY_HEADERS_DIR}/TreeNode.h
    ${LIBRARY_HEADERS_DIR}/Trie.h
    ${LIBRARY_HEADERS_DIR}/TrieNode.h
)
set(LIBRARY_SOURCE_DIR src)
set(LIBRARY_SOURCE
    ${LIBRARY_SOURCE_DIR}/assorted_methods.cpp
    ${LIBRARY_SOURCE_DIR}/BitVector.cpp
    ${LIBRARY_SOURCE_DIR}/Trie.cpp
    ${LIBRARY_SOURCE_DIR}/TrieNode.cpp
)

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCE}
)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)