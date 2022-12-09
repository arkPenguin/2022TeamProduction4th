
#pragma once

#include <AzCore/Component/Component.h>

#include <RenewProj/RenewProjBus.h>

namespace RenewProj
{
    class RenewProjSystemComponent
        : public AZ::Component
        , protected RenewProjRequestBus::Handler
    {
    public:
        AZ_COMPONENT(RenewProjSystemComponent, "{60F8A2D8-C827-4259-8942-E0B8DDF863A7}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RenewProjSystemComponent();
        ~RenewProjSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RenewProjRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
