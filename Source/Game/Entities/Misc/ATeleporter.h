#pragma once

#include "BaseEntity.h"

namespace Freeking::Entity::Misc
{
    class ATeleporter : public BaseEntity
    {
    public:

        ATeleporter();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityProperty& property) override;

    private:

    };
}
