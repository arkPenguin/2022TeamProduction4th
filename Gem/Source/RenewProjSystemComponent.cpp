
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "RenewProjSystemComponent.h"

namespace RenewProj
{
    void RenewProjSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<RenewProjSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<RenewProjSystemComponent>("RenewProj", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void RenewProjSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("RenewProjService"));
    }

    void RenewProjSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("RenewProjService"));
    }

    void RenewProjSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RenewProjSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RenewProjSystemComponent::RenewProjSystemComponent()
    {
        if (RenewProjInterface::Get() == nullptr)
        {
            RenewProjInterface::Register(this);
        }
    }

    RenewProjSystemComponent::~RenewProjSystemComponent()
    {
        if (RenewProjInterface::Get() == this)
        {
            RenewProjInterface::Unregister(this);
        }
    }

    void RenewProjSystemComponent::Init()
    {
    }

    void RenewProjSystemComponent::Activate()
    {
        RenewProjRequestBus::Handler::BusConnect();
    }

    void RenewProjSystemComponent::Deactivate()
    {
        RenewProjRequestBus::Handler::BusDisconnect();
    }
}
