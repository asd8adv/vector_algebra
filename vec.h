#include <math.h>
#include <iostream>
#include <array>

constexpr auto PI = 3.141592654;

namespace vec{



//i recomended used float or double for vec2<T>
template<typename T, size_t N>
struct vec {
	std::array<T, N> data;
	
	//product vector & scalar
	template<typename K>
	void operator*=(const K& scalar) {
		for (auto& it : data) {
			it = it * scalar;
		}
	}

	vec<T, N> operator-() const{
		vec<T, N> temp;
		for (size_t i = 0; i < N; i++) {
			temp.data[i] = - data[i];
		}
		return temp;
	}
};


//vector summ
template<typename T, size_t N>
vec<T, N> operator+(const vec<T, N>& lhs, const vec<T, N>& rhs) {
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = lhs.data[i] + rhs.data[i];
	}
	return temp;
}

//vector difference
template<typename T, size_t N >
vec<T, N> operator-(const vec<T, N>& lhs, const vec<T, N>& rhs) {
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = lhs.data[i] - rhs.data[i];
	}
	return temp;
}

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const vec<T,N>& vec) {
	for (auto it : vec.data) {
		os << it << " ";
	}
	return os;
}


//product vector & scalar
template<typename T, typename K, size_t N>
vec<T,N> operator*(const vec<T,N> & vec,const K& scalar) {
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = lhs.data[i] * rhs.data[i];
	}
	return temp;
}

template<typename T, size_t N>
vec<T,N> abs(const vec<T,N>& vec) {
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = abs(vec.data[i]);
	}
	return temp;
}

//theorem pythagoras 
template<typename T, size_t N>
float TheoremPythagoras(std::array<T,N> args) {
	float temp (0);
	for (auto it : vec.data) {
		temp = temp + (it * it);
	}
	return sqrt(temp);
}

//length vector
template<typename T, size_t N>
float LengthVec(const vec<T,N>& vec) {
	return TheoremPythagoras(vec.data);
}


//vector distance
template<typename T, size_t N>
float Distance(const vec<T, N>& lhs, const vec<T, N>& rhs) {
	return getlengthVec(lhs - rhs);
}

//get normilized vector
template<typename T, size_t N>
vec<T,N> Normilize(const vec<T,N>& value) {
	auto length = LengthVec(value);
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = value.data[i] / length;
	}
	return temp;
}

//scalar product
template<typename T, size_t N>
T Dot(const vec<T,N>& lhs, const vec<T,N>& rhs) {
	T temp(0);
	for (size_t i = 0; i < N; i++) {
		temp = temp + (lhs.data[i] * rhs.data[i]);
	}
	return temp;
}

//Angle for two vectors
template<typename T, size_t N>
float Angle(const vec<T,N>& lhs, const vec<T,N>& rhs) {
	return acos((Dot(lhs, rhs)) / (LengthVec(lhs) * LengthVec(rhs)));
}

template<typename T, size_t N>
float MathDot(const vec<T,N>& lhs, const vec<T,N>& rhs) {
	return LengthVec(lhs) * LengthVec(rhs) * cos(Angle(lhs, rhs));z
}

}//end namespace vec