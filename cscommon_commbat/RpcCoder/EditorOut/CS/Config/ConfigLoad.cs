using UnityEngine;
using System.Collections;

public class ConfigLoad : MonoBehaviour {

	private string textContent;

	public IEnumerator LoadConfig () {

		yield return StartCoroutine(LoadData("BaoShi.csv"));
		BaoShiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BaseAI.csv"));
		BaseAITable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BASEConfig.csv"));
		BASEConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Buff.csv"));
		BuffTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("equipAttr.csv"));
		equipAttrTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipColour.csv"));
		EquipColourTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipRank.csv"));
		EquipRankTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipStarRank.csv"));
		EquipStarRankTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipStartupo.csv"));
		EquipStartupoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Equipstar.csv"));
		EquipstarTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipStrengthen.csv"));
		EquipStrengthenTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Equiptupo.csv"));
		EquiptupoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Equip.csv"));
		EquipTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ExpandAI.csv"));
		ExpandAITable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FaBaoAttribute.csv"));
		FaBaoAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FaBao.csv"));
		FaBaoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("GodWeaponWake.csv"));
		GodWeaponWakeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("GodWeapon.csv"));
		GodWeaponTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeroColour.csv"));
		HeroColourTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeroJiBan.csv"));
		HeroJiBanTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeroTM.csv"));
		HeroTMTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Item.csv"));
		ItemTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LvUp.csv"));
		LvUpTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Military.csv"));
		MilitaryTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("NiudanBase.csv"));
		NiudanBaseTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Niudan.csv"));
		NiudanTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Rank.csv"));
		RankTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Section.csv"));
		SectionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ShopNormal.csv"));
		ShopNormalTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ShopPata.csv"));
		ShopPataTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ShopRongyu.csv"));
		ShopRongyuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ShopShetuan.csv"));
		ShopShetuanTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ShopSuipian.csv"));
		ShopSuipianTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Shop.csv"));
		ShopTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SpecialAttr.csv"));
		SpecialAttrTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Trigger.csv"));
		TriggerTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WuPinTypeID.csv"));
		WuPinTypeIDTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WuSheng.csv"));
		WuShengTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("XingShiFuMo.csv"));
		XingShiFuMoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Xingshi.csv"));
		XingshiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Localization.csv"));
		LocalizationTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Hero.csv"));
		HeroTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Skill.csv"));
		SkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Monster.csv"));
		MonsterTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Dungeons.csv"));
		DungeonsTable.Instance.LoadCsv(textContent);



		yield return true;
	}

    IEnumerator LoadData (string name) {

		string path = Ex.Utils.GetStreamingAssetsFilePath(name, "CSV");
	
		WWW www = new WWW(path);
		yield return www;

		textContent = www.text;
		yield return true;
	}
}
