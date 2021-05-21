modded class ActionLowerFlag {
	override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);

		TerritoryFlag flag = TerritoryFlag.Cast( action_data.m_Target.GetObject() );
		if (flag) flag.DECF_UpdateCF();
	}
}