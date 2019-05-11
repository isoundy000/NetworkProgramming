# 高并发网络编程
基于linux系统   
这里就不详细写了，主要时间去写代码了   
boost下载网址：https://www.boost.org/   
boost库编译方式：http://www.cnblogs.com/wondering/archive/2009/05/21/boost_setup.html
常用编译方法
./bjam stage --toolset=msvc-14.1 --without-graph --without-graph_parallel --without-math --without-mpi --without-python --without-serialization --without-wave --stagedir="D:boost\bin\vc14.1" link=static runtime-link=shared runtime-link=static threading=multi debug release