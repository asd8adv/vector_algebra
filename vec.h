#include <math.h>
#include <iostream>
#include <array>

constexpr auto PI = 3.141592654;

namespace vec{

//theorem pythagoras 
template<typename T, size_t N>
float EuclideanDistance(const std::array<T, N>& args) {
	float temp(0);
	for (auto it : args) {
		temp = temp + (it * it);
	}
	return sqrt(temp);
}

//recomended used float or double for vec<T>
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

	float LengthVec() const{
		return EuclideanDistance(data);
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
vec<T,N> operator*(const vec<T,N> & value,const K& scalar) {
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = value.data[i] * value.data[i];
	}
	return temp;
}

template<typename T, size_t N>
vec<T,N> abs(const vec<T,N>& value) {
	vec<T, N> temp;
	for (size_t i = 0; i < N; i++) {
		temp.data[i] = abs(value.data[i]);
	}
	return temp;
}

//length vector
template<typename T, size_t N>
float LengthVec(const vec<T,N>& value) {
	return EuclideanDistance(value.data);
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

//scalar product for not Euclid space
template<typename T, size_t N>
float MathDot(const vec<T,N>& lhs, const vec<T,N>& rhs) {
	return LengthVec(lhs) * LengthVec(rhs) * cos(Angle(lhs, rhs));
}

//cross product
template<typename T>
vec<T, 3> CrossProduct(const vec<T, 3>& lhs, const vec<T, 3>& rhs) {
	vec<T, 3> temp = { 0,0,0 };
	temp.data[0] = (lhs.data[1] * rhs.data[2]) - (lhs.data[2] * rhs.data[1]);
	temp.data[1] = -((lhs.data[0] * rhs.data[2]) - (lhs.data[2] * rhs.data[0]));
	temp.data[2] = (lhs.data[0] * rhs.data[1]) - (lhs.data[1] * rhs.data[0]);
	return temp;
}

template<typename T, size_t N>
float CrossLength(const vec<T, N>& lhs, const vec<T, N>& rhs) {
	return (lhs.LengthVec() * rhs.LengthVec()) * sin(Angle(lhs, rhs));
}

}//end namespace vec