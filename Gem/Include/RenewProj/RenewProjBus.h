
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RenewProj
{
    class RenewProjRequests
    {
    public:
        AZ_RTTI(RenewProjRequests, "{344BB5EF-44A3-4ABC-8F69-0103C72C98A8}");
        virtual ~RenewProjRequests() = default;
        // Put your public methods here
    };

    class RenewProjBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RenewProjRequestBus = AZ::EBus<RenewProjRequests, RenewProjBusTraits>;
    using RenewProjInterface = AZ::Interface<RenewProjRequests>;

} // namespace RenewProj
