/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_IENUMERABLE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/IEnumerable.hpp"
#endif

#ifndef _MAP_
#include <map>
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_TEMPLATE_LIST
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/List.hpp"
#endif

namespace Elysium::Communication::Service::Http::Headers
{
	class ELYSIUM_COMMUNICATION_API HttpHeaders : public Elysium::Core::Collections::IEnumerable<std::pair<Elysium::Core::String, Elysium::Core::Collections::Template::List<Elysium::Core::String>>>
	{
	public:
		virtual ~HttpHeaders();

		// ToDo: remove this functions as soon as IEnumerable and IEnumerator have been implemented in some way
		const std::map<Elysium::Core::String, Elysium::Core::Collections::Template::List<Elysium::Core::String>>& GetInternalHeaders() const;

		void Add(const Elysium::Core::String& Name, const Elysium::Core::Collections::Template::List<Elysium::Core::String> & Values);
		void Add(const Elysium::Core::String& Name, const Elysium::Core::String& Value);
		void Clear();
		bool Contains(const char16_t* Name) const;
		bool Contains(const Elysium::Core::String& Name) const;
		const Elysium::Core::Collections::Template::List<Elysium::Core::String>& GetValues(const char16_t* Name) const;
		const Elysium::Core::Collections::Template::List<Elysium::Core::String>& GetValues(const Elysium::Core::String& Name) const;
		bool Remove(const Elysium::Core::String& Name);
	protected:
		HttpHeaders();
		HttpHeaders(const HttpHeaders& Source);
		HttpHeaders(HttpHeaders&& Right) noexcept;

		HttpHeaders& operator=(const HttpHeaders& Source);
		HttpHeaders& operator=(HttpHeaders&& Right) noexcept;

		std::map<Elysium::Core::String, Elysium::Core::Collections::Template::List<Elysium::Core::String>> _Headers;
	};
}
#endif
