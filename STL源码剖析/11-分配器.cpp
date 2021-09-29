/*
所有的operator new()都会调用malloc()去分配内存，malloc()所提供的内存比需求的内存要大
overhead指除了要求的内存大小外，额外分配的内存部分。如果需求内存小，则overhead大
allocator中调用allocate/deallocate -> _Allocate() -> operator new() -> malloc()
               deallocate -> operator delete() -> free()
直接使用分配器的示例：
    int* p = allocator<int>().allocate(512, (int*)0);    // allocator<int>() 为创建一个临时变量，并不会真正去用它
    allocator<int>().deallocate(p, 512);     // 归还指针和内存大小   

使用其他分配器的示例：
vector<string, __gun_cxx::__pool_alloc<string>> vex;

*/