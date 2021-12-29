#include "RESTClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT
#include "../Elysium.Communication.Service.HTTP/StringContent.hpp"
#endif

#ifndef ELYSIUM_CORE_JSON_JSONTEXTREADER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Json/JsonTextReader.hpp"
#endif

#ifndef ELYSIUM_CORE_IO_STRINGREADER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/StringReader.hpp"
#endif


Elysium::Communication::Service::Rest::RestClient::RestClient()
	: _HttpClient(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4)
{ }
Elysium::Communication::Service::Rest::RestClient::~RestClient()
{ }

void Elysium::Communication::Service::Rest::RestClient::SetBaseAddress(const Elysium::Core::Uri & BaseAddress)
{
	_HttpClient.SetBaseAddress(BaseAddress);
}

void Elysium::Communication::Service::Rest::RestClient::Connect()
{
	_HttpClient.Connect();
}
void Elysium::Communication::Service::Rest::RestClient::Disconnect()
{
	_HttpClient.Disconnect();
}





using namespace Elysium::Communication::Service::Http;
using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::Json;

void Elysium::Communication::Service::Rest::RestClient::TestGET(const Elysium::Core::Utf8String & Path)
{
	HttpResponseMessage Response = _HttpClient.Get(Path);
	const StringContent* Content = static_cast<const StringContent*>(Response.GetContent());
	if (Content != nullptr)
	{
		Elysium::Core::Utf8String ContentAsString = Content->ReadAsString();
		StringReader Reader = StringReader(ContentAsString);
		JsonIOSettings Settings = JsonIOSettings(u8" ", u8"\t", u8"\n");
		JsonTextReader JsonReader = JsonTextReader(Settings, Reader);

		JsonReader.Read();
		const JsonToken StartToken = JsonReader.GetToken();
		if (StartToken == JsonToken::StartedArray)
		{
			while (Reader.Read())
			{
				JsonReader.Read();

				JsonReader.Read();
				if (JsonReader.GetToken() == JsonToken::None)
				{
					break;
				}
				JsonReader.Read();
				const Elysium::Core::Utf8String UserId = JsonReader.GetNodeValue();

				JsonReader.Read();
				JsonReader.Read();
				const Elysium::Core::Utf8String Id = JsonReader.GetNodeValue();

				JsonReader.Read();
				JsonReader.Read();
				const Elysium::Core::Utf8String Title = JsonReader.GetNodeValue();

				JsonReader.Read();
				JsonReader.Read();
				const Elysium::Core::Utf8String Completed = JsonReader.GetNodeValue();

				JsonReader.Read();
			}
		}
		else if (StartToken == JsonToken::StartedObject)
		{
			JsonReader.Read();
			JsonReader.Read();
			const Elysium::Core::Utf8String UserId = JsonReader.GetNodeValue();

			JsonReader.Read();
			JsonReader.Read();
			const Elysium::Core::Utf8String Id = JsonReader.GetNodeValue();

			JsonReader.Read();
			JsonReader.Read();
			const Elysium::Core::Utf8String Title = JsonReader.GetNodeValue();

			JsonReader.Read();
			JsonReader.Read();
			const Elysium::Core::Utf8String Completed = JsonReader.GetNodeValue();
		}
	}
}
