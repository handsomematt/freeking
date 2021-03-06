#pragma once

#include "BaseEntity.h"

namespace Freeking::Entity::Target
{
    class ACharacter : public BaseEntity
    {
    public:

        ACharacter();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityProperty& property) override;

    private:

    };
}
