modded class TerritoryFlag
{
    protected ref _Event _customEventInstance;

	void TerritoryFlag() {
        if (!m_IsTerritory && this._registeredInstance) GetGameLabs().RemoveEvent(this._registeredInstance);
	}

    void ~TerritoryFlag() {
        if (this._registeredInstance) GetGameLabs().RemoveEvent(this._registeredInstance);
		if (this._customEventInstance) DECF_RemoveCF();
    }

	void DECF_RemoveCF() {
		if (this._customEventInstance) GetGameLabs().RemoveEvent(_GetCustomEventInstance());
	}

	void DECF_AddCF() {
		_customEventInstance = new _Event(DECF_FormatTerritory(m_Territory.GetTerritoryName(), m_Territory.GetOwnerID(), m_Territory.GetTerritoryMembers(), Math.Round(GetRefresherTime01() * 100)), "flag", this);
		_SetCustomEventInstance(_customEventInstance);
		GetGameLabs().RegisterEvent(_customEventInstance);
	}

	void DECF_UpdateCF() {
		DECF_RemoveCF();
		DECF_AddCF();
	}

	void DECF_UpdateOrAddCF() {
		if (_GetCustomEventInstance()) {
			DECF_UpdateCF();
		} else {
			DECF_AddCF();
		}
	}

    override void AfterStoreLoad() {
        super.AfterStoreLoad();
		DECF_AddCF();
    }

	override void OnPartBuiltServer(notnull Man player, string part_name, int action_id) {
		super.OnPartBuiltServer(player, part_name, action_id );
		DECF_UpdateOrAddCF();
    }

    // Public API
    _Event _GetCustomEventInstance() {
        return this._customEventInstance;
    }

    void _SetCustomEventInstance(ref _Event _customEventInstance) {
        this._customEventInstance = _customEventInstance;
    }
}