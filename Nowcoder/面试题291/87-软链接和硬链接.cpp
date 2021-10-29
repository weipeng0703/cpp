// 题目
/*
软链接和硬链接区别
*/

// 解答
/*
为了解决文件共享问题，Linux引入了软链接和硬链接。
除了为Linux解决文件共享使用，还带来了隐藏文件路径、增加权限安全及节省存储等好处。

若1个inode号对应多个文件名，则为硬链接，即硬链接就是同一个文件使用了不同的别名,使用ln创建。

若文件用户数据块中存放的内容是另一个文件的路径名指向，则该文件是软连接。
软连接是一个普通文件，有自己独立的inode,但是其数据块内容比较特殊。
*/