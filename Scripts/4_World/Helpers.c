static string DECF_FormatTerritory(string name, string owner, ref array<ref ExpansionTerritoryMember> members, int raised) {
    string membersStr;
    for (int i=0; i < members.Count(); ++i) {
        membersStr = membersStr + "- " + members[i].GetName();
        if (members[i].GetID() == owner) membersStr = membersStr + " <strong>(Owner)<strong>";
        membersStr = membersStr + "<br />";
    }
    // return "<fieldset><legend><strong>" + name + "</strong> (Territory)<br /></legend>" + membersStr + "Raised: " + raised + "%</fieldset>";
    return "<fieldset><legend><strong>" + name + "</strong> (Territory)<br /></legend>" + membersStr + "</fieldset>";
}