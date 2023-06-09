#include "GameObject.h"

#include "json_utils.h"

bool GameObject::from_json(const std::string & filename, picojson::object & obj) {

	// this is the loader for the root class ..........
	// We do a lot of data validation here - it's important to know if the data is right

	if (!has_field<std::string>(obj, "Id")) {
		std::cerr << "filename : " << filename << " does not contain an Id property (or it is not a string)" << std::endl;
		return false;
	}

	if (!has_field<std::string>(obj, "Name")) {
                std::cerr << "filename : " << filename << " does not contain a Name Property (or it is not a string)" << std::endl;
                return false;
        }

        if (!has_field<std::string>(obj, "Description")) {
                std::cerr << "filename : " << filename << " does not contain a Description property (or it is not a string)" << std::endl;
                return false;
        }

        if (!has_field<std::string>(obj, "Takeable")) {
                std::cerr << "filename : " << filename << " does not contain a Takeable property (or it is not a string)" << std::endl;
                return false;
        }

        if (!has_field<std::string>(obj, "Moveable")) {
                std::cerr << "filename : " << filename << " does not contain a Moveable property (or it is not a string)" << std::endl;
                return false;
        }

	// we validated things, assign these values to our instance data

        id = obj["Id"].get<std::string>();
        name = obj["Name"].get<std::string>();
        description = obj["Description"].get<std::string>();
        moveable = obj["Moveable"].get<bool>();
        takeable = obj["Takeable"].get<bool>();

        return true;

}


