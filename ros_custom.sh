# deal with tinyxml2
# ln -s /usr/local/lib/libtinyxml.so.5.0 libtinyxml2.so.4

# set enviroment
_catkin_home=$(pwd)
echo $_catkin_home
export PATH="$_catkin_home/devel/:/opt/ros/kinetic/bin:$PATH"
export CMAKE_PREFIX_PATH="$CMAKE_PREFIX_PATH:$_catkin_home/devel"
export LD_LIBRARY_PATH="$_catkin_home/devel/lib:/usr/local/lib:$LD_LIBRARY_PATH"
export ROS_PACKAGE_PATH="$_catkin_home/devel/:$_catkin_home/src/:$ROS_PACKAGE_PATH"
export PKG_CONFIG_PATH="$_catkin_home/devel/lib/pkgconfig:$PKG_CONFIG_PATH"
unset _catkin_home
