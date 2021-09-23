// 尽量以const enum inline替换 #define


// 对于单纯常量，最好以const, enum, inline替换define
// 对于形似函数的宏（macros），最好改用inline函数替换#defines
#define ASPECT_RATIO 1.653

const double AspectRatio = 1.653;

// the enum_hack 补偿做法:一个属于枚举类型（enumerated type）的数值可权充ints被使用
class GamePlayer
{
private:
    enum{NumTurns = 5};

    int scores [NumTurns];


};  

#define CALL_WITH_MAX(a, b) f((a) > (b)? (a):(b))

template<typename T>
inline void CallWithMax(const T &a, const T &b)
{
    f(a > b? a : b);
}