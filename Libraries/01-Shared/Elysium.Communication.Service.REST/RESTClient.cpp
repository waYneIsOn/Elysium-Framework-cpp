#include "RESTClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT
#include "../Elysium.Communication.Service.HTTP/StringContent.hpp"
#endif

using namespace Elysium::Communication::Service::Http;
using namespace Elysium::Core;

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
		/*
		using (Stream stream = response.GetResponseStream())
		{
			using (StreamReader sr = new StreamReader(stream))
			{
				content = sr.ReadToEnd();
			}
		}
		var releases = JArray.Parse(content);
		*/
	}

	int x = 34;
}
