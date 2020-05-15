// 템플릿
template <typename T1, typename T2>
class Sample {};

// 부분 특수화 => 템플릿
template <typename T1>
class Sample<T1, int> {};

// 특수화 => 자료형 (타입)
template <>
class Sample<char, int> {};

