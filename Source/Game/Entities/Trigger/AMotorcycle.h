#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Trigger
{
    class AMotorcycle : public BaseEntity
    {
    public:

        AMotorcycle();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}