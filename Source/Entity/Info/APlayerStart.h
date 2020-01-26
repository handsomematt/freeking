#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Info
{
    class APlayerStart : public IEntity
    {
    public:

        APlayerStart();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}