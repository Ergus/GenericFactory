#pragma once

#include <map>
#include <functional>

template <typename KEY, typename T, typename... ARGS>
class GenericFactory {
public:
	// Esto es el prototipo del callback (constructor)
	typedef std::function<T(ARGS...)> create_callback;

private:
	// Y esta es la primera parte de la magia; basicamente un mapa <key, callback>
	std::map<KEY, create_callback> _callbacks;

	// Esta clase es un helper, no deberia tener nunca un objeto real construido
	// Ni ser copiable
	GenericFactory() = default;
	~GenericFactory() = default;

	GenericFactory(const GenericFactory&) = delete;
	GenericFactory& operator=(const GenericFactory&) = delete;

public:
	// Esto solo son las funciones mas basicas
	bool emplace(KEY id, create_callback createFn)
	{
		return _callbacks.emplace(id, createFn).second;
	}

	// Y esto basicamente sustituye al constructor
	T create(KEY id, ARGS... input)
	{
		return _callbacks.at(id)(input...);
	}

	// Y esto para acceder al mapa estatico que es privado
	static GenericFactory &getInstance()
	{
		// Y aqui la segunda parte de la magia... se pueden hacer las 2 en una,
		// pero asi es mejor, porque si esta funcion nunca se llama el static no
		// se crea.
		static GenericFactory obj;
		return obj;
	}
};
