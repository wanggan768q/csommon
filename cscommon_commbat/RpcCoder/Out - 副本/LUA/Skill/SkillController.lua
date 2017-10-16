SkillController = class("SkillController",BaseController)

function SkillController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=SkillController.new(SkillModel:getInstance())
	end 
	return self.instance
end

function SkillController:ctor(model)
	SkillController.super.ctor(self,model)
	
	

end

function SkillController:modelDataUpdate( syncId, idx )

end










