
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RenewProjSystemComponent.h"

namespace RenewProj
{
    class RenewProjModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RenewProjModule, "{CC4ABB58-03F6-4619-A955-03890860D139}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RenewProjModule, AZ::SystemAllocator, 0);

        RenewProjModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RenewProjSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RenewProjSystemComponent>(),
            };
        }
    };
}// namespace RenewProj

AZ_DECLARE_MODULE_CLASS(Gem_RenewProj, RenewProj::RenewProjModule)
