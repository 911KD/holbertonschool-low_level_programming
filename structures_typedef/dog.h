#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the dog's owner
 *
 * Description: holds the name, age and owner of a dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
