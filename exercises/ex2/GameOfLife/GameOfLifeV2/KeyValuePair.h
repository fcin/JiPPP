#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H

struct KeyValuePair
{
	unsigned int Key;
	unsigned int Value;
	unsigned int Data;

	inline KeyValuePair(unsigned int key, unsigned int value) : Key(key), Value(value) { }
	inline KeyValuePair(unsigned int key, unsigned int value, unsigned int data) : Key(key), Value(value), Data(data) { }
};

#endif