/*
Iterator需要遵循的原则：
    iterator必须有能力回答algorithm的提问：iterator_type,difference_type,value_type,reference,pointer

Traits:
    traits机器必须有能力分辨它所获得的iterator是class iterator T还是native pointer to T
    利用partial specialization可达到目标

*/

