#pragma once

#pragma warning( disable : 26812 )
#include <cassert>
#include "hash-functions.hpp"
#include "../../includes/json.hpp"
// Must come after json.hpp
#include "../externally-generated/key-derivation-parameters.hpp"

/**
 * Exception classes for key derivation
 */
class ClientNotAuthorizedException: public std::invalid_argument
{
	public:
	ClientNotAuthorizedException(const char* what =
    "The client is not authorized to use this key"
  ): std::invalid_argument(what) {};
};

class InvalidKeyDerivationOptionsJsonException: public std::invalid_argument
{
	public:
	InvalidKeyDerivationOptionsJsonException(const char* what =
		"Invalid JSON key derivation options"
	):
		std::invalid_argument(what) {};
};
class InvalidKeyDerivationOptionValueException: public std::invalid_argument
{
	public:
	InvalidKeyDerivationOptionValueException(const char* what) :
		std::invalid_argument(what) {};
};


/**
 * This class represents key generation options,
 * provided in JSON format, as an immutable class.
 */
class KeyDerivationOptions {

private:
	nlohmann::json keyDerivationOptionsExplicit;
public:
	const std::string keyDerivationOptionsJson;
	KeyDerivationOptionsJson::KeyType keyType;
	KeyDerivationOptionsJson::Algorithm algorithm;
  unsigned int keyLengthInBytes;
	std::vector<std::string> restrictToClientApplicationsIdPrefixes;
	HashFunction *hashFunction;
	bool includeOrientationOfFacesInKey;

	~KeyDerivationOptions();

  /**
   * Create a KeyDerivationOptions class from the JSON representation
   * of the key generation options.
   **/
  KeyDerivationOptions(
		const std::string &keyDerivationOptionsJson,
		const KeyDerivationOptionsJson::KeyType keyTypeExpected =
			KeyDerivationOptionsJson::KeyType::_INVALID_KEYTYPE_
	);

	const void validate(const std::string applicationId) const;

	KeyDerivationOptions(
		const std::string &keyDerivationOptionsJson,
		const std::string applicationId,
		const KeyDerivationOptionsJson::KeyType keyTypeExpected = KeyDerivationOptionsJson::KeyType::_INVALID_KEYTYPE_
	) : KeyDerivationOptions(keyDerivationOptionsJson, keyTypeExpected) {
		validate(applicationId);
	}


	const std::string keyDerivationOptionsJsonWithAllOptionalParametersSpecified(
		int indent = -1,
	  const char indent_char = ' '
	) const;

};
