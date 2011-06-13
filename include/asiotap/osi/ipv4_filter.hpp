/*
 * libasiotap - A portable TAP adapter extension for Boost::ASIO.
 * Copyright (C) 2010-2011 Julien Kauffmann <julien.kauffmann@freelan.org>
 *
 * This file is part of libasiotap.
 *
 * libasiotap is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libasiotap is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libasiotap in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file ipv4_filter.hpp
 * \author Julien KAUFFMANN <julien.kauffmann@freelan.org>
 * \brief An IPv4 filter class.
 */

#ifndef ASIOTAP_OSI_IPV4_FILTER_HPP
#define ASIOTAP_OSI_IPV4_FILTER_HPP

#include "filter.hpp"
#include "ipv4_frame.hpp"

#include "ipv4_helper.hpp"
#include "ethernet_helper.hpp"

namespace asiotap
{
	namespace osi
	{
		/**
		 * \brief The IPv4 filter.
		 */
		template <typename ParentFilterType>
		class ipv4_filter : public filter<ipv4_frame, ParentFilterType>
		{
			public:

				/**
				 * \brief Constructor.
				 * \param parent The parent filter.
				 */
				ipv4_filter(ParentFilterType& parent);
		};

		/**
		 * \brief Check if a frame is valid.
		 * \param frame The frame.
		 * \param buf The buffer. If the return value is true, buf will be updated to indicate the payload of the frame.
		 * \return true on success.
		 */
		bool check_frame(const_ipv4_helper frame, boost::asio::const_buffer& buf);

		/**
		 * \brief The frame parent match function.
		 * \param parent The parent frame.
		 * \return true if the frame matches the parent frame.
		 */
		template <>
		bool frame_parent_match<ipv4_frame>(const_ethernet_helper parent);

		template <typename ParentFilterType>
		inline ipv4_filter<ParentFilterType>::ipv4_filter(ParentFilterType& parent) : filter<ipv4_frame, ParentFilterType>(parent)
		{
		}

		template <>
		inline bool frame_parent_match<ipv4_frame>(const_ethernet_helper parent)
		{
			return (parent.protocol() == IP_PROTOCOL);
		}
	}
}

#endif /* ASIOTAP_OSI_IPV4_FILTER_HPP */
