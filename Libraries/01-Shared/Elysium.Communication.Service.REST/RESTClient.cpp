#include "RESTClient.hpp"

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

	HttpResponseMessage Response(&Request);
	_HttpClient.ReceiveResponse(Response);

	int x = 34;
}
