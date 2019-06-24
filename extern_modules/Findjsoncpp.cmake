MESSAGE("FIND jsoncpp in modules")
SET(jsoncpp_FOUND 1)

#这里可以用FIND_LIBRARY FIND_PATH命令根据备选路径，版本号来真正查找，但是没有必要这么灵活
SET(jsoncpp_INCLUDE_DIR /usr/local/include)
SET(jsoncpp_LIBRARY /usr/local/lib)

