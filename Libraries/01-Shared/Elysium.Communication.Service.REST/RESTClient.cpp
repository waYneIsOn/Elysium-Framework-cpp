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

using namespace Elysium::Communication::Service::Http;
using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::Json;

Elysium::Communication::Service::REST::RESTClient::RESTClient()
{
}
Elysium::Communication::Service::REST::RESTClient::~RESTClient()
{
}

void Elysium::Communication::Service::REST::RESTClient::Connect(const Elysium::Core::Uri & Uri)
{
	_HttpClient.Connect(Uri);
}
void Elysium::Communication::Service::REST::RESTClient::Disconnect()
{
	_HttpClient.Disconnect();
}

void Elysium::Communication::Service::REST::RESTClient::TestGET(const Elysium::Core::Uri & Uri)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Uri);
	Request.GetHeaders().SetHost(Uri.GetHost());
	_HttpClient.SendRequest(Request);

	HttpResponseMessage Response = _HttpClient.ReceiveResponse(Request);
	const StringContent* Content = static_cast<const StringContent*>(Response.GetContent());
	if (Content != nullptr)
	{
		String ContentAsString = Content->ReadAsString();
		StringReader Reader = StringReader(ContentAsString);
		JsonIOSettings Settings = JsonIOSettings(u" ", u"\t", u"\n");
		JsonTextReader JsonReader = JsonTextReader(Settings, Reader);

		JsonReader.Read();
		const JsonToken StartToken = JsonReader.GetToken();
		if (StartToken == JsonToken::StartedArray)
		{

		}
		else if (StartToken == JsonToken::StartedObject)
		{
			JsonReader.Read();
			JsonReader.Read();
			const String UserId = JsonReader.GetNodeValue();

			JsonReader.Read();
			JsonReader.Read();
			const String Id = JsonReader.GetNodeValue();

			JsonReader.Read();
			JsonReader.Read();
			const String Title = JsonReader.GetNodeValue();

			JsonReader.Read();
			JsonReader.Read();
			const String Completed = JsonReader.GetNodeValue();
		}
	}
}
