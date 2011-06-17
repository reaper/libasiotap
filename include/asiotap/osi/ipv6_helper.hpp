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
 * \file ipv6_helper.hpp
 * \author Julien KAUFFMANN <julien.kauffmann@freelan.org>
 * \brief An IPv6 helper class.
 */

#ifndef ASIOTAP_OSI_IPV6_HELPER_HPP
#define ASIOTAP_OSI_IPV6_HELPER_HPP

#include "helper.hpp"
#include "ipv6_frame.hpp"

namespace asiotap
{
	namespace osi
	{
		/**
		 * \brief The const ipv6 helper class.
		 */
		typedef const_helper<ipv6_frame> const_ipv6_helper;

		/**
		 * \brief The mutable ipv6 helper class.
		 */
		typedef mutable_helper<ipv6_frame> mutable_ipv6_helper;

		/**
		 * \brief The const ipv6 helper implementation class.
		 */
		template <>
		class _const_helper_impl<ipv6_frame> : public _base_const_helper<ipv6_frame>
		{
			public:

				/**
				 * \brief Get the version.
				 * \return The version.
				 */
				uint8_t version() const;

				/**
				 * \brief Get the Internet Header Length, in words.
				 * \return The Internet Header Length, in words.
				 */
				uint8_t ihl() const;

				/**
				 * \brief Get the Internet Header Length, in bytes.
				 * \return The Internet Header Length, in bytes.
				 */
				size_t header_length() const;

				/**
				 * \brief Get the Type Of Service.
				 * \return The Type Of Service.
				 */
				uint8_t tos() const;

				/**
				 * \brief Get the total length.
				 * \return The total length.
				 */
				size_t total_length() const;

				/**
				 * \brief Get the payload length.
				 * \return The payload length.
				 */
				size_t payload_length() const;

				/**
				 * \brief Get the identification.
				 * \return The indentification.
				 */
				uint16_t identification() const;

				/**
				 * \brief Get the flags.
				 */
				uint8_t flags() const;

				/**
				 * \brief Get the position fragment.
				 * \return The position fragment.
				 */
				uint16_t position_fragment() const;

				/**
				 * \brief Get the time-to-live.
				 * \return The time-to-live.
				 */
				uint8_t ttl() const;

				/**
				 * \brief Get the protocol.
				 * \return The protocol.
				 */
				uint8_t protocol() const;

				/**
				 * \brief Get the checksum.
				 * \return The checksum.
				 */
				uint16_t checksum() const;

				/**
				 * \brief Get the source address.
				 * \return The source address.
				 */
				boost::asio::ip::address_v6 source() const;

				/**
				 * \brief Get the destination address.
				 * \return The destination address.
				 */
				boost::asio::ip::address_v6 destination() const;

				/**
				 * \brief Compute the checksum.
				 * \return The checksum.
				 */
				uint16_t compute_checksum() const;

				/**
				 * \brief Verify the checksum.
				 * \return true if the checksum is valid.
				 */
				bool verify_checksum() const;

			protected:

				/**
				 * \brief Create a helper from a frame type structure.
				 * \param buf The buffer to refer to.
				 */
				_const_helper_impl(boost::asio::const_buffer buf);
		};

		/**
		 * \brief The mutable ipv6 helper implementation class.
		 */
		template <>
		class _mutable_helper_impl<ipv6_frame> : public _base_mutable_helper<ipv6_frame>
		{
			public:

				/**
				 * \brief Get the version.
				 * \return The version.
				 */
				uint8_t version() const;

				/**
				 * \brief Set the version.
				 * \param version The version.
				 */
				void set_version(uint8_t version) const;

				/**
				 * \brief Get the Internet Header Length, in words.
				 * \return The Internet Header Length, in words.
				 */
				uint8_t ihl() const;

				/**
				 * \brief Set the Internet Header Length, in words.
				 * \param ihl The Internet Header Length, in words.
				 */
				void set_ihl(uint8_t ihl) const;

				/**
				 * \brief Get the Internet Header Length, in bytes.
				 * \return The Internet Header Length, in bytes.
				 */
				size_t header_length() const;

				/**
				 * \brief Get the Type Of Service.
				 * \return The Type Of Service.
				 */
				uint8_t tos() const;

				/**
				 * \brief Set the Type Of Service.
				 * \param tos The Type Of Service.
				 */
				void set_tos(uint8_t tos) const;

				/**
				 * \brief Get the total length.
				 * \return The total length.
				 */
				size_t total_length() const;

				/**
				 * \brief Set the total length.
				 * \param total_length The total length.
				 */
				void set_total_length(size_t total_length) const;

				/**
				 * \brief Get the payload length.
				 * \return The payload length.
				 */
				size_t payload_length() const;

				/**
				 * \brief Get the identification.
				 * \return The indentification.
				 */
				uint16_t identification() const;

				/**
				 * \brief Set the identification.
				 * \param identification The identification.
				 */
				void set_identification(uint16_t identification) const;

				/**
				 * \brief Get the flags.
				 */
				uint8_t flags() const;

				/**
				 * \brief Set the flags.
				 * \param flags The flags.
				 */
				void set_flags(uint8_t flags) const;

				/**
				 * \brief Get the position fragment.
				 * \return The position fragment.
				 */
				uint16_t position_fragment() const;

				/**
				 * \brief Set the position fragment.
				 * \param position_fragment The position fragment.
				 */
				void set_position_fragment(uint16_t position_fragment) const;

				/**
				 * \brief Get the time-to-live.
				 * \return The time-to-live.
				 */
				uint8_t ttl() const;

				/**
				 * \brief Set the time-to-live.
				 * \param ttl The time-to-live.
				 */
				void set_ttl(uint8_t ttl) const;

				/**
				 * \brief Get the protocol.
				 * \return The protocol.
				 */
				uint8_t protocol() const;

				/**
				 * \brief Set the protocol.
				 * \param protocol The protocol.
				 */
				void set_protocol(uint8_t protocol) const;

				/**
				 * \brief Get the checksum.
				 * \return The checksum.
				 */
				uint16_t checksum() const;

				/**
				 * \brief Set the checksum.
				 * \param checksum The checksum.
				 */
				void set_checksum(uint16_t checksum) const;

				/**
				 * \brief Get the source address.
				 * \return The source address.
				 */
				boost::asio::ip::address_v6 source() const;

				/**
				 * \brief Set the source address.
				 * \param source The source address.
				 */
				void set_source(boost::asio::ip::address_v6 source) const;

				/**
				 * \brief Get the destination address.
				 * \return The destination address.
				 */
				boost::asio::ip::address_v6 destination() const;

				/**
				 * \brief Set the destination address.
				 * \param destination The destination address.
				 */
				void set_destination(boost::asio::ip::address_v6 destination) const;

				/**
				 * \brief Compute the checksum.
				 * \return The checksum.
				 */
				uint16_t compute_checksum() const;

				/**
				 * \brief Verify the checksum.
				 * \return true if the checksum is valid.
				 */
				bool verify_checksum() const;

			protected:

				/**
				 * \brief Create a helper from a frame type structure.
				 * \param buf The buffer to refer to.
				 */
				_mutable_helper_impl(boost::asio::mutable_buffer buf);
		};

		inline uint8_t _const_helper_impl<ipv6_frame>::version() const
		{
			return (frame().version_ihl & 0xF0) >> 4;
		}

		inline uint8_t _const_helper_impl<ipv6_frame>::ihl() const
		{
			return (frame().version_ihl & 0x0F);
		}

		inline size_t _const_helper_impl<ipv6_frame>::header_length() const
		{
			return ihl() * sizeof(uint32_t);
		}

		inline uint8_t _const_helper_impl<ipv6_frame>::tos() const
		{
			return frame().service_type;
		}

		inline size_t _const_helper_impl<ipv6_frame>::total_length() const
		{
			return ntohs(frame().total_length);
		}

		inline size_t _const_helper_impl<ipv6_frame>::payload_length() const
		{
			return total_length() - header_length();
		}

		inline uint16_t _const_helper_impl<ipv6_frame>::identification() const
		{
			return ntohs(frame().identification);
		}

		inline uint8_t _const_helper_impl<ipv6_frame>::flags() const
		{
			return static_cast<uint8_t>((frame().flags_fragment & 0xE000) >> 13);
		}

		inline uint16_t _const_helper_impl<ipv6_frame>::position_fragment() const
		{
			return (frame().flags_fragment & 0x1FFF);
		}

		inline uint8_t _const_helper_impl<ipv6_frame>::ttl() const
		{
			return frame().ttl;
		}

		inline uint8_t _const_helper_impl<ipv6_frame>::protocol() const
		{
			return frame().protocol;
		}

		inline uint16_t _const_helper_impl<ipv6_frame>::checksum() const
		{
			return ntohs(frame().header_checksum);
		}

		inline boost::asio::ip::address_v6 _const_helper_impl<ipv6_frame>::source() const
		{
			return boost::asio::ip::address_v6(ntohl(frame().source.s_addr));
		}

		inline boost::asio::ip::address_v6 _const_helper_impl<ipv6_frame>::destination() const
		{
			return boost::asio::ip::address_v6(ntohl(frame().destination.s_addr));
		}

		inline bool _const_helper_impl<ipv6_frame>::verify_checksum() const
		{
			return compute_checksum() == 0x0000;
		}

		inline _const_helper_impl<ipv6_frame>::_const_helper_impl(boost::asio::const_buffer buf) :
			_base_const_helper<ipv6_frame>(buf)
		{
		}

		inline uint8_t _mutable_helper_impl<ipv6_frame>::version() const
		{
			return (frame().version_ihl & 0xF0) >> 4;
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_version(uint8_t _version) const
		{
			frame().version_ihl = (frame().version_ihl & 0x0F) | ((_version & 0x0F) << 4);
		}

		inline uint8_t _mutable_helper_impl<ipv6_frame>::ihl() const
		{
			return (frame().version_ihl & 0x0F);
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_ihl(uint8_t _ihl) const
		{
			frame().version_ihl = (frame().version_ihl & 0xF0) | (_ihl & 0x0F);
		}

		inline size_t _mutable_helper_impl<ipv6_frame>::header_length() const
		{
			return ihl() * sizeof(uint32_t);
		}

		inline uint8_t _mutable_helper_impl<ipv6_frame>::tos() const
		{
			return frame().service_type;
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_tos(uint8_t _tos) const
		{
			frame().service_type = _tos;
		}

		inline size_t _mutable_helper_impl<ipv6_frame>::total_length() const
		{
			return ntohs(frame().total_length);
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_total_length(size_t _total_length) const
		{
			frame().total_length = htons(_total_length);
		}

		inline size_t _mutable_helper_impl<ipv6_frame>::payload_length() const
		{
			return total_length() - header_length();
		}

		inline uint16_t _mutable_helper_impl<ipv6_frame>::identification() const
		{
			return ntohs(frame().identification);
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_identification(uint16_t _identification) const
		{
			frame().identification = htons(_identification);
		}

		inline uint8_t _mutable_helper_impl<ipv6_frame>::flags() const
		{
			return static_cast<uint8_t>((frame().flags_fragment & 0xE000) >> 13);
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_flags(uint8_t _flags) const
		{
			frame().flags_fragment = (frame().flags_fragment & 0x1FFF) | ((static_cast<uint16_t>(_flags) & 0x0007) << 13);
		}

		inline uint16_t _mutable_helper_impl<ipv6_frame>::position_fragment() const
		{
			return (frame().flags_fragment & 0x1FFF);
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_position_fragment(uint16_t _position_fragment) const
		{
			frame().flags_fragment = (frame().flags_fragment & 0xE000) | (_position_fragment & 0x1FFF);
		}

		inline uint8_t _mutable_helper_impl<ipv6_frame>::ttl() const
		{
			return frame().ttl;
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_ttl(uint8_t _ttl) const
		{
			frame().ttl = _ttl;
		}

		inline uint8_t _mutable_helper_impl<ipv6_frame>::protocol() const
		{
			return frame().protocol;
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_protocol(uint8_t _protocol) const
		{
			frame().protocol = _protocol;
		}

		inline uint16_t _mutable_helper_impl<ipv6_frame>::checksum() const
		{
			return ntohs(frame().header_checksum);
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_checksum(uint16_t _checksum) const
		{
			frame().header_checksum = htons(_checksum);
		}

		inline boost::asio::ip::address_v6 _mutable_helper_impl<ipv6_frame>::source() const
		{
			return boost::asio::ip::address_v6(ntohl(frame().source.s_addr));
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_source(boost::asio::ip::address_v6 _source) const
		{
			frame().source.s_addr = htonl(_source.to_ulong());
		}

		inline boost::asio::ip::address_v6 _mutable_helper_impl<ipv6_frame>::destination() const
		{
			return boost::asio::ip::address_v6(ntohl(frame().destination.s_addr));
		}

		inline void _mutable_helper_impl<ipv6_frame>::set_destination(boost::asio::ip::address_v6 _destination) const
		{
			frame().destination.s_addr = htonl(_destination.to_ulong());
		}

		inline bool _mutable_helper_impl<ipv6_frame>::verify_checksum() const
		{
			return compute_checksum() == 0x0000;
		}

		inline _mutable_helper_impl<ipv6_frame>::_mutable_helper_impl(boost::asio::mutable_buffer buf) :
			_base_mutable_helper<ipv6_frame>(buf)
		{
		}
	}
}

#endif /* ASIOTAP_OSI_IPV6_HELPER_HPP */
