/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPSTATUSCODE
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPSTATUSCODE

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				enum class HttpStatusCode : long
				{
					// specific implementation values
					Unknown = 0,

					// 100 - informational
					Continue = 100,
					SwitchingProtocols = 101,

					// 200 - success
					OK = 200,
					Created = 201,
					Accepted = 202,
					NonAuthoritativeInformation = 203,
					NoContent = 204,
					ResetContent = 205,
					PartialContent = 206,

					// 300 - redirection
					Ambiguous = 300,
					MultipleChoices = 300,
					Moved = 301,
					MovedPermanently = 301,
					Found = 302,
					Redirect = 302,
					RedirectMethod = 303,
					SeeOther = 303,
					NotModified = 304,
					UseProxy = 305,
					Unused = 306,
					RedirectKeepVerb = 307,
					TemporaryRedirect = 307,

					// 400 - client error
					BadRequest = 400,
					Unauthorized = 401,
					PaymentRequired = 402,
					Forbidden = 403,
					NotFound = 404,
					MethodNotAllowed = 405,
					NotAcceptable = 406,
					ProxyAuthenticationRequired = 407,
					RequestTimeout = 408,
					Conflict = 409,
					Gone = 410,
					LengthRequired = 411,
					PreconditionFailed = 412,
					RequestEntityTooLarge = 413,
					RequestUriTooLong = 414,
					UnsupportedMediaType = 415,
					RequestedRangeNotSatisfiable = 416,
					ExpectationFailed = 417,
					UpgradeRequired = 426,

					// 500 - server error
					InternalServerError = 500,
					NotImplemented = 501,
					BadGateway = 502,
					ServiceUnavailable = 503,
					GatewayTimeout = 504,
					HttpVersionNotSupported = 505,
				};
			}
		}
	}
}
#endif